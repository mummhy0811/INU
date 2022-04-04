import java.util.*;

public class Algorithm_EDF implements Scheduler {

	public Vector<Job> schedule(int t, int numberOfProcs, Vector<Job> readyQueue, Vector<Task> taskset){
		Comparator<Job> comp = Comparators.EDFComparator(t);
		Collections.sort(readyQueue, comp);
		
		return readyQueue;
	}
}
