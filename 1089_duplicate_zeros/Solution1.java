// Implement queue for extra storage easy method
class Solution {
    public void duplicateZeros(int[] arr) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                q.add(0);
                q.add(0);
            } else {
                q.add(arr[i]);
            }
            int first_element = q.poll();
            arr[i] = first_element;
        }
    }
}
