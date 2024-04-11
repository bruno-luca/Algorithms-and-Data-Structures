package PriorityQueue;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;

/**
 *
 * @param <E> type of the element in the priority queue
 */
public class PriorityQueue <E> implements AbstractQueue <E>{
    private HashMap<E, Integer> hashedHeap;
    private ArrayList<E> heap;
    private Comparator<E> c;

    public PriorityQueue(Comparator<E> comparator){
        this.hashedHeap = new HashMap<>();
        this.heap = new ArrayList<>();
        this.c = comparator;
    }

    public boolean empty(){
        return heap.size() == 0;
    }

    public boolean push(E e){
        if(hashedHeap.get(e) == null) {
            heap.add(e);
            int i = heap.size() - 1, iParent = getParent(i);
            E tmp;
            while (i > 0 && this.c.compare(heap.get(iParent), heap.get(i)) > 0) {
                tmp = heap.get(i);
                heap.set(i, heap.get(iParent));
                heap.set(iParent, tmp);
                i = iParent;
                iParent = getParent(i);
            }
            hashedHeap.put(e, 1);

            return true;
        }else return false;
    }

    public boolean contains(E e){
        if(hashedHeap.get(e) != null) return true;
        else return false;
    }

    public E top(){
        if(!this.empty()) return heap.get(0);
        else return null;
    }

    public void pop(){
        if(!this.empty()){
            heap.set(0, heap.get(heap.size()-1));
            E removed = heap.remove(heap.size()-1);
            hashedHeap.remove(removed);
            if(!this.empty()) heapify(0);
        }
    }

    private void heapify(int index){
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int heapSize = heap.size();

        if (leftChild < heapSize && this.c.compare(heap.get(leftChild), heap.get(largest)) < 0) {
            largest = leftChild;
        }

        if (rightChild < heapSize && this.c.compare(heap.get(rightChild), heap.get(largest)) < 0) {
            largest = rightChild;
        }

        if (largest != index) {
            E temp = heap.get(index);
            heap.set(index, heap.get(largest));
            heap.set(largest, temp);
            heapify(largest);
        }
    }

    public boolean remove(E e){
        if (contains(e)) {
            int index = heap.indexOf(e);
            hashedHeap.remove(e);
            heap.set(index, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            heapify(index);
            return true;
        } else {
            return false;
        }
    }

    @Override
    public String toString() {
        String ret = "";
        for(E e : heap) ret += e.toString() + ", ";
        return ret;
    }

    private int getParent(int i){
        if(i % 2 == 0) return i/2 - 1;
        else return i/2;
    }

    public int getSize(){
        return heap.size();
    }
}
