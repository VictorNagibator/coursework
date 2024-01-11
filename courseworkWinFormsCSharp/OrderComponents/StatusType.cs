using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public enum StatusType { ONHOLD, INPROCESS, FINISHED };

    public static class StatusTypeConverter
    {
        public static StatusType StringToStatusType(string type)
        {
            switch(type)
            {
                case "ONHOLD":
                case "В ожидании":
                    return StatusType.ONHOLD;
                case "INPROCESS":
                case "В ремонте":
                    return StatusType.INPROCESS;
                case "FINISHED":
                case "Завершен":
                    return StatusType.FINISHED;
                default:
                    throw new Exception("Invalid status type");
            }
        }
    }
}
