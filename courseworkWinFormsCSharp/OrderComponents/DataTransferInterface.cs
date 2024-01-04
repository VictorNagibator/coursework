using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public enum DataTransferInterface { PATA, SATA, SAS, NVME }

    public static class DataTransferInterfaceConverter
    {
        public static DataTransferInterface StringToDataTransferInterface(string transferInterface)
        {
            if (Enum.TryParse<DataTransferInterface>(transferInterface, out var result))
            {
                return result;
            }
            else
            {
                throw new ArgumentException("Некорректный тип интерфейса!");
            }
        }
    }
}
