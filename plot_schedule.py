import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("schedule.csv")

fig, ax = plt.subplots()
for i, row in df.iterrows():
    ax.barh(row["Process"], row["End"] - row["Start"], left=row["Start"], height=0.5)

ax.set_xlabel("Time")
ax.set_title("Gantt Chart - CPU Scheduling")
plt.tight_layout()
plt.savefig("gantt_chart.png")
plt.show()
