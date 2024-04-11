package Graph;

/**
 *
 * @param <V> type of the graph node
 * @param <L> type of the graph edge weight
 */
public interface AbstractEdge<V,L extends Comparable>{
    public V getStart();
    public V getEnd();
    public L getLabel();
};
