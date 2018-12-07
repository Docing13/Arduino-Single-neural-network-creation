import serial
import time

ser = serial.Serial('/dev/ttyACM0',9600)
time.sleep(1)
f = open('datasetRoma2.txt','w')
samples = 200;
for i in range(samples):
        try:

            st = ser.readline()
            st = st.decode()
            print(st)
            f.write(st)
            time.sleep(0.1)
        except:
            pass
f.close()
print("DONE")
