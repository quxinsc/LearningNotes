```cpp
#include<iostream>
struct pid_uint{
    unsigned int Kp;//比例P
    unsigned int Ki;//积分
    unsigned int Kd;//微分
    unsigned int Ur;//最大值
    unsigned int Adjust;//接受输出数据
    unsigned int En;//使能
    unsigned int speedSet;//目标值
    unsigned int speedNow;//测量值
    unsigned int U_kk;//上次输出
    unsigned int ekk;//上次误差
    unsigned int ekkk;//此次误差
};
void reset_Uk(struct pid_uint *p);
struct pid_uint pid_Task_Letf;
struct pid_uint pid_Task_Right;

void PID_Init(void)
{
//乘以1024原因避免出现浮点数运算，全部是整数运算，这样PID控制器运算速度会更快
/***********************左轮速度pid****************************/
    pid_Task_Letf.Kp = 1024 * 0.5;//0.4
    pid_Task_Letf.Ki = 1024 * 0;    
    pid_Task_Letf.Kd = 1024 * 0.08; 
    pid_Task_Letf.Ur = 1024 * 4000;
    pid_Task_Letf.Adjust   = 0;
    pid_Task_Letf.En       = 1;
    pid_Task_Letf.speedSet = 0;
    pid_Task_Letf.speedNow = 0;
    reset_Uk(&pid_Task_Letf);       
/***********************右轮速度pid****************************/
    pid_Task_Right.Kp = 1024 * 0.35;//0.2
    pid_Task_Right.Ki = 1024 * 0;   //不使用积分
    pid_Task_Right.Kd = 1024 * 0.06; 
    pid_Task_Right.Ur = 1024 * 4000;
    pid_Task_Right.Adjust   = 0;
    pid_Task_Right.En       = 1;
    pid_Task_Right.speedSet = 0;
    pid_Task_Right.speedNow = 0;
    reset_Uk(&pid_Task_Right);
}

/***********************************************************************************************
 函 数 名：void reset_Uk(PID_Uint *p)
 功    能：初始化U_kk,ekk,ekkk
 说    明：在初始化时调用，改变PID参数时有可能需要调用
 入口参数：PID单元的参数结构体 地址
************************************************************************************************/

void reset_Uk(struct pid_uint *p)
{
    p->U_kk=0;//上次执行量
    p->ekk=0;//上次误差
    p->ekkk=0;//上上次误差
}

int  PID_common(int set,int Measure,struct pid_uint *p)
{
    int Error=0,Out=0;

    Error=Measure-set; //误差量 
/*#################比例Proportion：与偏差量成正比####################*/
/*==================================================================
       积分Integral增幅器：加快回正/解决小偏差
过小：小偏差不能回正                   过大：容易超出目标，系统表现迟钝
=====================================================================
       微分Derivative抑制器：根据偏差变化量，快速限制超出目标
过小：超出目标                         过大：目标附近高频抖动
===================================================================*/
    Out=p->Kp*(Error - p->ekk) + p->Ki*Error + p->Kd*(Error - 2*p->ekk + p->ekkk)+p->U_kk;//执行量
    Out=(Error*p->Kp)+(Error*p->Ki+p->U_kk)+(Error-p->ekk+p->ekkk-p->ekkk)*p->Kd;
    p->U_kk=Out;
    p->ekkk=p->ekk;//存储上次偏差量
    p->ekk=Error;//存储此次偏差量

    if(Out>(p->Ur))//防止超过阈值                                        
        Out=p->Ur;
    if(Out<-(p->Ur))
        Out=-(p->Ur);

    return Out>>10; 
}
void Pid_Which(struct pid_uint *pl, struct pid_uint *pr)
{
    /**********************左轮速度pid*************************/
    if(pl->En == 1)
    {                                   
        pl->Adjust = -PID_common(pl->speedSet, pl->speedNow, pl);       
    }   
    else
    {
        pl->Adjust = 0;
        reset_Uk(pl);
        pl->En = 2; 
    }
    /***********************右轮速度pid*************************/
    if(pr->En == 1)
    {
        pr->Adjust = -PID_common(pr->speedSet, pr->speedNow, pr);       
    }   
    else
    {
        pr->Adjust = 0;
        reset_Uk(pr);
        pr->En = 2; 
    }
}

/*******************************************************************************
 * 函数名：Pid_Ctrl(int *leftMotor,int  *rightMotor)
 * 描述  ：Pid控制
 *******************************************************************************/

void Pid_Ctrl(int *leftMotor,int  *rightMotor)
{
    Pid_Which(&pid_Task_Letf, &pid_Task_Right); 
    *leftMotor  += pid_Task_Letf.Adjust;//输出pid数据到指针
    *rightMotor += pid_Task_Right.Adjust;
}
int leftSpeedNow  =0;
int rightSpeedNow =0;

int leftSpeeSet   = -300;//mm/s
int rightSpeedSet = -300;//mm/s

int main(void)
{ 
    int motorLeft,motorRight;
    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//禁用JTAG 启用 SWD

    //MY_NVIC_PriorityGroupConfig(2); //=====设置中断分组

    //delay_init();                   //=====延时函数初始化
    //LED_Init();                     //=====LED初始化    程序灯    

    //usart3_init(9600);              //=====串口3初始化  蓝牙 发送调试信息

    //Encoder_Init_TIM2();            //=====初始化编码器1接口
    //Encoder_Init_TIM4();            //=====初始化编码器2接口

    //Motor_Init(7199,0);             //=====初始化PWM 10KHZ，用于驱动电机 如需初始化驱动器接口

    //TIM3_Int_Init(50-1,7200-1);     //=====定时器初始化 5ms一次中断

    PID_Init();                     //=====PID参数初始化

    while(1)
    {
        //给速度设定值和实时值赋值
        pid_Task_Letf.speedSet  = leftSpeeSet;//设置目标值
        pid_Task_Right.speedSet = rightSpeedSet;
        pid_Task_Letf.speedNow  = leftSpeedNow;//设置当前值
        pid_Task_Right.speedNow = rightSpeedNow;

        //执行PID控制函数
        Pid_Ctrl(&motorLeft,&motorRight);//传入PWM数据指针

        //根据PID计算的PWM数据进行设置PWM
        //Set_Pwm(motorLeft,motorRight);

        //打印速度
        std::cout<<("%d,%d\r\n",leftSpeedNow,rightSpeedNow);
    } 
}
//
////5ms 定时器中断服务函数
//
//void TIM3_IRQHandler(void)                            //TIM3中断
//{
//    if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否
//    {
//        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);   //清除TIMx的中断待处理位
//
//        Get_Motor_Speed(&leftSpeedNow,&rightSpeedNow);//计算电机速度
//
//        Led_Flash(100);                               //程序闪烁灯
//    }
//}
```