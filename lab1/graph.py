import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
data_all = pd.read_csv('out_all.csv')
data_lin = pd.read_csv('lin2.csv')
data_sqr = pd.read_csv('sqr.csv')
dataA = pd.read_csv('A.csv')
dataB = pd.read_csv('B.csv')

data_all.to_csv('out_all.csv')

data_sqr.to_csv('sqr.csv', header=['N', 'time_sqr'], index=False)
data_lin.to_csv('lin2.csv', header=['N', 'time_lin'], index=False)
dataA.to_csv('A.csv', header=['N', 'time_A'], index=False)
dataB.to_csv('B.csv', header=['N', 'time_B'], index=False)
dataA1 = pd.read_csv('A.csv')
dataB1 = pd.read_csv('B.csv')
data_ln = pd.read_csv('lin2.csv')
data_sq = pd.read_csv('sqr.csv')


fig_lin = plt.subplots()
plt.scatter(dataB1["N"], dataB1["time_B"])
#x = np.arange(100, 1000100)
#lin_m = np.polyfit(np.log2(data_all["N"]), data_all["bad_log_time"], 1)
#plt.plot(x, [0.5*np.log2(i)+lin_m[1]*0 for i in x], label="t = 0.5*log(N)")
#plt.legend()
#print(lin_m)
#y = [lin_m[0]*i+lin_m[1] for i in x]
#plt.plot(x, y)
#plt.scatter(data_all["N"], data_all["bad_lin_time"])
#plt.scatter(data_all["N"], data_all["av_lin_time"], color="red")
plt.show()

#inear_model_fn = np.poly1d(lin_m)
#x_s = np.arange(100, 1000000)
#y_s = [2**(lin_m[0]*i+lin_m[1]) for i in x_s]
#plt.plot(x_s, y_s, color="red")
#plt.scatter(data_all["N"], data_all["bad_log_time"], color="green")
#plt.scatter(data_all["N"], data_all["av_log_time"], color="black")
#plt.show()