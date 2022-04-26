def logger_params(params: str, log_file: str):
    """ Write header to log file """

    flog = open(log_file, 'w')
    flog.write(params + '\n')
    flog.close()


def log_data(line: str, log_file: str):
    """ log data as str in log file """

    with open(log_file, "a") as flog:
        flog.write(str(line)[2:-3] + '\n')
