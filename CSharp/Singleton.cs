

namespace SingletonPattern
{

    public sealed class Singleton
    {
       private static readonly Singleton SingletonInstance;

       private Singleton() { }
      
       static Singleton()
        {
            SingletonInstance = new Singleton();
        }

        public static Singleton GetInstance
        {
            get { return SingletonInstance; }
        }
  }

    class TestProgram
    {
        static void Main(string[] args)
        {
            //Setting refernces to Singleton through it's Property 
            var singleton1 = Singleton.GetInstance;
            var singleton2 = Singleton.GetInstance;
        }
    }

}
