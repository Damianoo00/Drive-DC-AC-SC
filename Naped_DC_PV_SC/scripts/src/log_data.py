from pydoc import visiblename


class LogData:
    def __init__(self, label, visible) -> None:
        self.label = label
        self.visible = visible  #for eventualy GUI
        self.values = []
    
    def AddValue(self, value):
        self.values.append(value)