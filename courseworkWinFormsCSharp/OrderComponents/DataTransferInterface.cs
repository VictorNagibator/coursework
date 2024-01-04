using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public enum DataTransferInterface { PATA, SATA, SAS, NVME }

    internal static class DataTransferInterfaceConverter
    {
        public static string DataTransferInterfaceToString(DataTransferInterface transferInterface)
        {
            switch (transferInterface)
            {
                case DataTransferInterface.PATA:
                    return "PATA";
                case DataTransferInterface.SATA:
                    return "SATA";
                case DataTransferInterface.SAS:
                    return "SAS";
                case DataTransferInterface.NVME:
                    return "NVMe";
                default:
                    throw new ArgumentException("Некорректный тип интерфейса!");
            }
        }

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
