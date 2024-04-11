package Main;

import Graph.AbstractEdge;

import java.util.Comparator;

/**
 *
 * @param <T>: type of the element to ber compared.
 */
public class MyComparator<T> implements Comparator<T> {
    @Override
    /**
     * Compare element a with element b. If a and b are instances of AbstracEdges then compare the label attribute,
     * if are instances of Comparable then use native compareTo function, throw error otherwise.
     */
    public int compare(T a, T b) {
        if(a instanceof AbstractEdge<?,?> && b instanceof AbstractEdge<?,?>){
            return ((AbstractEdge<?, ?>) a).getLabel().compareTo(((AbstractEdge<?, ?>) b).getLabel());
        }else if(a instanceof Comparable<?> && b instanceof Comparable<?>){
            return ((Comparable<T>) a).compareTo(b);
        }else{
            throw new UnsupportedOperationException();
        }
    }
}

