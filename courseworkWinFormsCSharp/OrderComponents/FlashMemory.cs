using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public enum FlashMemoryType { SLC, MLC, NOR, NAND, NAND3D }

    public static class FlashMemoryTypeConverter
    {
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
