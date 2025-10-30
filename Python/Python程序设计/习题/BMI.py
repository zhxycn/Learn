"""
编写一个程序，分别提示用户输入他们的身高 (单位: 米) 和体重 (单位: 公斤).

根据公式 BMI = 体重 / 身高 ^ 2 计算用户的身体质量指数 (BMI).

输出计算出的 BMI, 结果保留一位小数.

根据计算出的 BMI, 判断并输出对应的健康状况:

BMI < 18.5: "您的体重过轻"

18.5 <= BMI < 24: "您的体重正常"

24 <= BMI < 28: "您的体重过重"

BMI >= 28: "您的体重肥胖"
"""

height = float(input("请输入您的身高(米): "))
weight = float(input("请输入您的体重(公斤): "))

bmi = weight / (height ** 2)

print(f"您的BMI指数为: {bmi:.1f}")

if bmi < 18.5:
    print("您的体重过轻")
elif 18.5 <= bmi < 24:
    print("您的体重正常")
elif 24 <= bmi < 28:
    print("您的体重过重")
else:
    print("您的体重肥胖")
