import java.util.HashSet;import java.util.LinkedList;import java.util.Queue;

class fifo
{
	// Method to find page faults using FIFO
	static int pageFaults(int pages[], int n, int capacity)
	{
		// To represent set of current pages. We use
		// an unordered_set so that we quickly check
		// if a page is present in set or not
		HashSet<Integer> s = new HashSet<>(capacity);
	
		// To store the pages in FIFO manner
		Queue<Integer> indexes = new LinkedList<>() ;
		int page_faults = 0;            // Start from initial page
		for (int i=0; i<n; i++)
		{
			if (s.size() < capacity)            // Check if the set can hold more pages
			{
				if (!s.contains(pages[i]))          // Insert it into set if not present // already which represents page fault
				{   s.add(pages[i]);
	                page_faults++;          // increment page fault
	                indexes.add(pages[i]);      // Push the current page into the queue
				}
			}
			else {        // If the set is full then need to perform FIFO // i.e. remove the first page of the queue from // set and queue both and insert the current page
				if (!s.contains(pages[i]))          // Check if current page is not already // present in the set
				{
					int val = indexes.peek();   //Pop the first page from the queue
					indexes.poll();
					s.remove(val);  // Remove the indexes page
					s.add(pages[i]);    // insert the current page
					indexes.add(pages[i]);  // push the current page into // the queue
					page_faults++;  // Increment page faults
				}
			}
		}
		return page_faults;
	}
public static void main(String args[])	{
		int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
		int capacity = 4;
		System.out.println(pageFaults(pages, pages.length, capacity));
	}
}