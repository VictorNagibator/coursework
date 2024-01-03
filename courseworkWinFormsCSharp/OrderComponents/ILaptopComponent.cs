using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    internal interface ILaptopComponent
    {
        string GetComponentName();
        string ToString();
        JObject ToJson();
        void FromJson(JObject data);
    }
}
