import serial
import matplotlib.pyplot as plt
import time

def main():
    ser = serial.Serial('COM10', 9600)  

    acc_x_data = []
    acc_y_data = []
    acc_z_data = []
    time_data = []

    try:
        while True:
            data = ser.readline().decode().strip()
            values = data.split(',')
            if len(values) == 6:
                acc_x, acc_y, acc_z = map(float, values[:3])

                acc_x_data.append(acc_x)
                acc_y_data.append(acc_y)
                acc_z_data.append(acc_z)
                time_data.append(time.time())

                plt.clf()
                plt.plot(time_data, acc_x_data, label='Acc X')
                plt.plot(time_data, acc_y_data, label='Acc Y')
                plt.plot(time_data, acc_z_data, label='Acc Z')
                plt.legend()
                plt.xlabel('Time (s)')
                plt.ylabel('Acceleration (m/s^2)')
                plt.title('Acceleration Data')
                plt.grid(True)
                plt.pause(0.01)

    except KeyboardInterrupt:
        ser.close()
        plt.show()

if __name__ == "__main__":
    main()