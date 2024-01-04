using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public enum RAMType { DDR, DDR2, DDR3, DDR4, DDR5 }

    public static class RAMTypeConverter
    {
        public static RAMType StringToRAMType(string type)
        {
            if (Enum.TryParse<RAMType>(type, out var result))
            {
                return result;
            }
            else
            {
                throw new ArgumentException("Некорректный тип оперативной памяти!");
            }
        }

        public static int RAMTypeToInt(RAMType type)
        {
            return (int)type;
        }
    }
}
