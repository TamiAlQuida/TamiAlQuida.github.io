from datetime import datetime

datetime_1 = datetime.now()
datetime_1_str = datetime_1.strftime("%Y-%m-%d_%H_%M_%S") #convert datetime to string

print(datetime_1_str)