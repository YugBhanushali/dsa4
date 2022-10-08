import matplotlib.pyplot as plt
revList=[]
days=[]
revList.append(0)
days.append(1)
revList.append(10000)
days.append(2)
revList.append(20000)
days.append(3)
plt.plot(revList,days)
plt.xlabel('Revenue')
plt.ylabel('Days')
plt.title('Revenue vs Days')
plt.show()
netList=[]
netList.append(0)
netList.append(1000)
netList.append(1000)
plt.plot(netList,days)
plt.xlabel('Net Income')
plt.ylabel('Days')
plt.title('Net Income vs Days')
plt.show()
