package Graph;

/**
 *
 * @param <V>: type of the graph's node
 * @param <L>: type of the edge weight
 */
public class Edge<V,L extends Comparable> implements AbstractEdge<V,L>{
    private V start;
    private V end;
    private L label;

    public Edge(V start, V end, L label){
        this.start = start;
        this.end = end;
        this.label = label;
    }

    @Override
    public V getStart() {
        return this.start;
    }

    @Override
    public V getEnd() {
        return this.end;
    }

    @Override
    public L getLabel() {
        return this.label;
    }
}
