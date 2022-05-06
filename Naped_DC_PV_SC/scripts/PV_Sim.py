import pyvisa
import serial
import argparse


def DeviceInfo(device: pyvisa.resources.serial.SerialInstrument):
    """ send request for device info via rs232 """
    print(device.query('*idn?'))


def SetOutputState(device: pyvisa.resources.serial.SerialInstrument,  state: bool):
    """ Set 1 or 0 as output state of device """
    device.write('OUTPut:STATe ' + str(state))
    


def SetVoltage(device: pyvisa.resources.serial.SerialInstrument, Volt: float):
    """ Set voltage value on device """
    device.write(':VOLTage ' + str(Volt))


def SetCurrent(device: pyvisa.resources.serial.SerialInstrument, Curr: float) -> None:
    """ Set current value on device """
    device.write(':CURRent '+str(Curr))


def GetCurrent(device: pyvisa.resources.serial.SerialInstrument) -> float:
    """ Request of actual current value on device and return it """
    response = device.query(':CURRent?')
    return response


def GetVoltage(device: pyvisa.resources.serial.SerialInstrument) -> float:
    """ Request of actual voltage value on device and return it """
    response = device.query(':VOLTage?')
    return response

def GetOutputState(device: pyvisa.resources.serial.SerialInstrument) -> float:
    """ Request of actual output state value on device and return it """
    response = device.query('OUTPut:STATe?')
    return response

def PV_charactreristic(device: pyvisa.resources.serial.SerialInstrument, voltage: int):
    """ Not made: 
        will return current value based of PV characteristic and actual voltage"""
    pass


parser = argparse.ArgumentParser(
    description="Symulate PV charactreristic by setting correct current to measured voltage")
parser.add_argument('--arduino_port', default="COM3",
                    help="Set arduino USB port [default=COM3]")
parser.add_argument('--dc_supply_port', default="COM7",
                    help="Set dc supply USB port[default=COM7]")

if __name__ == "__main__":
    args = parser.parse_args()

    rm = pyvisa.ResourceManager()

    # connect supply via rs232
    supply = rm.open_resource(args.arduino_port)
    
    # connect arduino via uart
    arduino = serial.Serial(args.dc_supply_port)
    
    # Test comunication
    DeviceInfo(supply)
    
    # Open output of supply
    SetOutputState(supply, 1)
    
    # infinity loop
    while(True):
        
        # read voltage value from arduino uart 
        PV_voltage = arduino.readline()
        
        # Set current based of PV charateristic
        SetCurrent(supply, PV_charactreristic(supply, PV_voltage))
