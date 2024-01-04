using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public enum FlashMemoryType { SLC, MLC, NOR, NAND, NAND3D }

    internal static class FlashMemoryTypeConverter
    {
        public static string FlashMemoryTypeToString(FlashMemoryType type)
        {
            switch (type)
            {
                case FlashMemoryType.SLC:
                    return "SLC";
                case FlashMemoryType.MLC:
                    return "MLC";
                case FlashMemoryType.NOR:
                    return "NOR";
                case FlashMemoryType.NAND:
                    return "NAND";
                case FlashMemoryType.NAND3D:
                    return "3D NAND";
                default:
                    throw new ArgumentException("Некорректный тип флеш-памяти!");
            }
        }

        public static FlashMemoryType StringToFlashMemoryType(string type)
        {
            if (Enum.TryParse<FlashMemoryType>(type, out var result))
            {
                return result;
            }
            else
            {
                throw new ArgumentException("Некорректный тип флеш-памяти!");
            }
        }
    }
}
