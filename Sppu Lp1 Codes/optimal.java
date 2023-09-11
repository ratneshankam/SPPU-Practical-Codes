// Java program to demonstrate optimal page // replacement algorithm.
import java.io.*;
import java.util.*;

class optimal {
	// Function to check whether a page exists // in a frame or not
	static boolean search(int key, int[] fr)
	{
		for (int i = 0; i < fr.length; i++)
			if (fr[i] == key)
				return true;
		return false;
	}
	// Function to find the frame that will not be used // recently in future after given index in page[0..n-1]
	static int predict(int page[], int[] fr, int n, int index) {
		// Store the index of pages which are going // to be used recently in future
		int res = -1, farthest = index;
		for (int i = 0; i < fr.length; i++) {
			int j;
			for (j = index; j < n; j++) {
				if (fr[i] == page[j]) {
					if (j > farthest) {
						farthest = j;
						res = i;
						System.out.println("The farthest frame: " + farthest);
						System.out.println("The res: " + res);
						System.out.println();
					}
					break;
				}
			}
			// If a page is never referenced in future,
			// return it.
			if (j == n){
				return i;}
		}
		// If all of the frames were not in future, // return any of them, we return 0. Otherwise // we return res.
		return (res == -1) ? 0 : res;
	}
	static void optimalPage(int page[], int n, int capacity) {
		// Create an array for given number of // frames and initialize it as empty.
		int[] fr = new int[capacity];
		// Traverse through page reference array // and check for miss and hit.
		int hit = 0;
		int index = 0;
		for (int i = 0; i < n; i++) {
			// Page found in a frame : HIT
			if (search(page[i], fr)) {
				hit++;
				continue;
			}
			// Page not found in a frame : MISS	// If there is space available in frames.
			if (index < capacity) {
				fr[index++] = page[i];	
			} else {					// Find the page to be replaced.
				int j = predict(page, fr, n, i + 1);
				fr[j] = page[i];
			}
		}
		System.out.println("No. of hits = " + hit);
		System.out.println("No. of misses = " + (n - hit));
	}
	public static void main(String[] args) {			// driver function
		int page[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
		// int page[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
		int n = page.length;
		int capacity = 4;
		optimalPage(page, n, capacity);
	}
}
