'''
Author: quxinsc 2224721143quxin@gmail.com
Date: 2024-06-18 17:49:29
LastEditors: quxinsc 2224721143quxin@gmail.com
LastEditTime: 2024-06-18 17:49:47
FilePath: \Code\test.py
Description: 
Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
'''
def generate_attenuation_values():
    # 各位的衰减值
    attenuation_steps = [0.25, 0.5, 1, 2, 4, 8, 16]
    num_bits = len(attenuation_steps)
    
    # 生成所有可能的衰减值
    attenuation_values = []
    for i in range(2**num_bits):
        total_attenuation = 0
        for bit in range(num_bits):
            if i & (1 << bit):
                total_attenuation += attenuation_steps[bit]
        attenuation_values.append(total_attenuation)
    
    # 打印结果
    print("All possible attenuation values:")
    for value in sorted(attenuation_values):
        print(f"{value:.2f}dB")

# 调用函数生成并打印表格
generate_attenuation_values()