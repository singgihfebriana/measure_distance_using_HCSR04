from tkinter import*
from time import*
import serial

open_port='/dev/ttyACM0'
baudrate=9600
class measure_distance:
    def __init__(self,master):
        self.master=master
        master.title("Measuring")
        master.geometry("200x200")
        connect=serial.Serial(open_port,baudrate)
        self.data_analog=Label(master,text="0"+"Cm",font=("arial",40))
        self.data_analog.pack()

        while (True):
            data=connect.readline()
            raw_data=data.decode()
            arduino_analog_data=raw_data.rstrip()
            self.data_analog["text"]=[arduino_analog_data]
            root.update()
            sleep(1)
root=Tk()
object_measure=measure_distance(root)
root.mainloop()

