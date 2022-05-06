import argparse
import os

def clear_project() -> None:
    command = f"git submodule deinit --all"
    os.system(command)

    # clear platforio.ini file
    open("platformio.ini", 'w').close()

def activate_submodule(submodule: str, board: str, uart_baudrate: str) -> None:
    command = f"git submodule update --init src\{submodule}"
    os.system(command)

    with open("platformio.ini", 'a') as fappend:
        fappend.write(
            f"[env:{submodule}]\n\
            platform = atmelavr\n\
            board = {board}\n\
            framework = arduino\n\
            src_filter = -<*> +<{submodule}/> +<share/>\n\
            lib_deps = mathertel/RotaryEncoder@^1.5.2\n\
            monitor_speed = {uart_baudrate}\n"
        )


parser = argparse.ArgumentParser(
    description="Tool to managment submodules in our project")
parser.add_argument('-clear', action='store_true', default=False,
                    help="Deactive all submodules and clear platformio.ini file")
parser.add_argument('-activate', action='store_true', default=False,
                    help="Activate submodule and ceate neccesery platformio.ini lines")
parser.add_argument('--submodule', default="SYSTEM_CTR",
                    help="Set submodule name")
parser.add_argument('--board', default="uno",
                    help="Set arduino board")
parser.add_argument('--uart_baudrate', default="115200",
                    help="Set uart baudrate for board")


if __name__ == "__main__":
    args = parser.parse_args()

    if args.clear:
        clear_project()
    if args.activate:
        activate_submodule(args.submodule, args.board, args.uart_baudrate)
