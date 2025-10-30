"""
编写一个 Python 程序 CurrencyConvert.py.

程序运行后提示用户输入带有单位 (CNY 或 USD) 的金额, 例如 500 CNY 或 70 USD, 单位不区分大小写.

程序根据单位判断是人民币转换为美元, 还是美元转换为人民币.

假设固定汇率为 1 USD = 7.0 CNY.

输出转换后的结果, 保留两位小数, 并附上正确的货币单位.

如果用户输入的格式不符合要求，则提示用户输入格式错误.
"""


rate = 7.0
user_input = input("请输入金额和单位 (例如: 500 CNY 或 70 USD): ").strip()

try:
    currency = user_input[-3:].upper()
    amount = float(user_input[:-3])

    match currency:
        case "CNY":
            converted_amount = amount / rate
            print(f"{amount:.2f} CNY = {converted_amount:.2f} USD")
        case "USD":
            converted_amount = amount * rate
            print(f"{amount:.2f} USD = {converted_amount:.2f} CNY")
        case _:
            raise ValueError
except ValueError:
    print("输入格式错误")
