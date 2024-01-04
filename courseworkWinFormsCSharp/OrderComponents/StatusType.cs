using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public enum StatusType { ONHOLD, INPROCESS, FINISHED };

    public static class StatusTypeConverter
    {
        public static StatusType StringToStatusType(string type)
        {
            if (Enum.TryParse<StatusType>(type, out var result))
            {
                return result;
            }
            else
            {
                throw new ArgumentException("Некорректный статус заказа!");
            }
        }
    }
}
