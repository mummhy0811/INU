import java.util.*;

public class Comparators {
	
	public static final double error = 0.0000001;
	
	public static Comparator<Job> RMComparator(final int t, final Vector<Task> taskset) {
		return new Comparator<Job>() {

			public int compare(Job j1, Job j2) {
				int index1 = j1.TaskIndex;
				int index2 = j2.TaskIndex;
				
				Task task1 = taskset.get(index1);
				Task task2 = taskset.get(index2);							
				
				double period1 = task1.Period;
				double period2 = task2.Period;													 

				return (period1<period2 ? -1 : (period1>period2 ? 1:(index1 < index2 ? -1: 1)));			
				}
		};
	}
	

	
	public static Comparator<Job> EDFComparator(final int t) {
		return new Comparator<Job>() {
			public int compare(Job j1, Job j2) {			
				
					double deadline1=j1.Deadline;
					double deadline2=j2.Deadline;
					double exectime1=j1.execTime;
					double exectime2=j1.execTime;

					return(deadline1<deadline2 ? -1 : (deadline1>deadline2 ? 1:(exectime1 > exectime2 ? -1: 1)));
				}
		};
	}

}
