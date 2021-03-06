import argparse
import os


def clear_project() -> None:
    """ Deinit all git submodules and clear platforio.ini file """
    command = f"git submodule deinit --all"
    os.system(command)

    # clear platforio.ini file
    open("platformio.ini", 'w').close()


def activate_submodule(submodule: str, board: str, uart_baudrate: str, debug_mode: bool) -> None:
    """ Init and update git submodule and add necessery lines to platformio.ini file """
    command = f"git submodule update --init src\{submodule}"
    os.system(command)

    rm_confilcted_src_files = ""

    if debug_mode:
        rm_confilcted_src_files = "-<share/uart.cpp>"

    with open("platformio.ini", 'a') as fappend:
        content = f"[env:{submodule}]\n\
            platform = atmelavr\n\
            board = {board}\n\
            framework = arduino\n\
            build_src_filter = -<*> +<{submodule}/> +<share/> {rm_confilcted_src_files}\n\
            test_build_src = yes\n\
            lib_deps = mathertel/RotaryEncoder@^1.5.2\n\
            monitor_speed = {uart_baudrate}\n"
        if debug_mode:
            content += "debug_tool = avr-stub\n\
                        debug_port = COM3\n"
        fappend.write(content)


parser = argparse.ArgumentParser(
    description="Tool to managment submodules in our project")
parser.add_argument('-clear', action='store_true', default=False,
                    help="Deactive all submodules and clear platformio.ini file")
parser.add_argument('-activate', action='store_true', default=False,
                    help="Activate submodule and ceate neccesery platformio.ini lines")
parser.add_argument('--submodule', default="SYSTEM_CTR",
                    help="Set submodule name [default=SYSTEM_CTR]")
parser.add_argument('--board', default="uno",
                    help="Set arduino board [default=uno]")
parser.add_argument('--uart_baudrate', default="115200",
                    help="Set uart baudrate for board [default=115200]")
parser.add_argument('-debug', action='store_true', default=False,
                    help="rm conflicted uart.cpp src file")


if __name__ == "__main__":
    args = parser.parse_args()

    if args.clear:
        clear_project()
    if args.activate:
        activate_submodule(args.submodule, args.board,
                           args.uart_baudrate, args.debug)
