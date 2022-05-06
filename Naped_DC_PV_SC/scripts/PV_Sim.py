import pyvisa
import serial
import argparse

# def SelectDevice():

#     rm = pyvisa.ResourceManager()

#     if (len(rm.list_resources()) == 1):
#         device = rm.open_resource(rm.list_resources()[0])
#     else:
#         num_of_res = 0
#         for res in rm.list_resources:
#             print(f"{num_of_res}. {res}")
#         num_of_res = input("Select device (by num): ")
#         device = rm.open_resource(rm.list_resources(num_of_res))
#     return device


def DeviceInfo(device: pyvisa.resources.serial.SerialInstrument):
    print(device.query('*idn?'))


def SetOutputState(device: pyvisa.resources.serial.SerialInstrument,  state: bool):
    device.write('OUTPut:STATe ' + str(state))
    


def SetVoltage(device: pyvisa.resources.serial.SerialInstrument, Volt: float):
    device.write(':VOLTage ' + str(Volt))


def SetCurrent(device: pyvisa.resources.serial.SerialInstrument, Curr: float) -> None:
    device.write(':CURRent '+str(Curr))


def GetCurrent(device: pyvisa.resources.serial.SerialInstrument) -> float:
    response = device.query(':CURRent?')
    return response


def GetVoltage(device: pyvisa.resources.serial.SerialInstrument) -> float:
    response = device.query(':VOLTage?')
    return response

def GetOutputState(device: pyvisa.resources.serial.SerialInstrument) -> float:
    response = device.query('OUTPut:STATe?')
    return response

def PV_charactreristic(device: pyvisa.resources.serial.SerialInstrument, voltage: int):
    pass


parser = argparse.ArgumentParser(
    description="Symulate PV charactreristic by setting correct current to measured voltage")
parser.add_argument('--arduino_port', default="COM3",
                    help="Set arduino USB port")
parser.add_argument('--dc_supply_port', default="COM7",
                    help="Set dc supply USB port")

if __name__ == "__main__":
    args = parser.parse_args()

    rm = pyvisa.ResourceManager()

    supply = rm.open_resource(args.arduino_port)
    arduino = serial.Serial(args.dc_supply_port)
    DeviceInfo(supply)
    SetOutputState(supply, 1)
    
    while(True):
        PV_voltage = arduino.readline()
        SetCurrent(supply, PV_charactreristic(supply, PV_voltage))
