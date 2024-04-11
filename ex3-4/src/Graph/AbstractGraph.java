package Graph;

import java.util.Collection;
/**
 *
 * @param <V>: type of the graph's node
 * @param <L>: type of the edge weight
 */
public interface AbstractGraph<V,L extends Comparable> {
    public boolean isDirected();
    public boolean isLabelled();
    public boolean addNode(V a);
    public boolean addEdge(V a, V b, L l);
    public boolean containsNode(V a);
    public boolean containsEdge(V a, V b);
    public boolean removeNode(V a);
    public boolean removeEdge(V a, V b);
    public int numNodes();
    public int numEdges();
    public Collection<V> getNodes();
    public Collection<? extends AbstractEdge<V,L>> getEdges();
    public Collection<V> getNeighbours(V a);
    public L getLabel(V a, V b);
};
