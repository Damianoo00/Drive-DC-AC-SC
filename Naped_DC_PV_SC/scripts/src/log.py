def logger_params(params: str):
    flog = open('../data/log.txt', 'w')
    flog.write(params + '\n')
    flog.close()


def log_data(line: str):
    with open('../data/log.txt', "a") as flog:
        flog.write(str(line)[2:-3] + '\n')
