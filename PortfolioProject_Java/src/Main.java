public class Main {

    public static void main(String[] args) throws InterruptedException {
        var start = System.nanoTime();
        int min = 0;
        int max = 20;
        int value = 0;

        Counter counterIncrement = new Counter(Counter.Operation.Increment,value, max);
        Thread threadInc = new Thread(counterIncrement);
        Counter counterDecrement = new Counter(Counter.Operation.Decrement);
        Thread threadDec = new Thread(counterDecrement);

        threadInc.start();
        threadInc.join();
        value = counterIncrement.GetFinalInt();
        counterDecrement.SetVal(value);
        counterDecrement.SetEndVal(min);
        threadDec.start();
        threadDec.join();
        var stop = System.nanoTime();
        System.out.println("Duration of execution: " + (stop-start) + " nanoseconds");
    }
}
