using Newtonsoft.Json.Linq;
using System.IO;

namespace courseworkWinFormsCSharp.DataManagers
{
    internal static class FileInfo
    {
        public static string Path
        {
            get
            {
                if (string.IsNullOrEmpty(Path))
                {
                    using (StreamReader properties = new StreamReader("..\\properties.json"))
                    {
                        Path = JObject.Parse(properties.ReadToEnd()).GetValue("lastFile").ToString();
                    }
                }
                return Path;
            }
            set
            {
                Path = value;
                OrdersData.LoadOrders(Path);
            }
        }
    }
}
