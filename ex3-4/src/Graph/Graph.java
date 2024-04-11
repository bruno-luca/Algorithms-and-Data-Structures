package Graph;

import java.util.*;

/**
 *
 * @param <V>: type of the graph's node
 * @param <L>: type of the edge weight
 */
public class Graph<V,L extends Comparable> implements AbstractGraph<V,L> {
    private boolean directed;
    private boolean labeled;

    private Map<V, Collection<Edge<V,L>>> nodes;

    public Graph(boolean directed, boolean labeled){
        this.directed = directed;
        this.labeled = labeled;
        this.nodes = new HashMap<>();
    }

    @Override
    public boolean isDirected() {
        return this.directed;
    } //-- O(1)

    @Override
    public boolean isLabelled() {
        return this.labeled;
    } //-- O(1)

    @Override
    public boolean addNode(V a) { //-- O(1)
        boolean added = false;
        if(!nodes.containsKey(a)){
            nodes.put(a, new HashSet<>());
            added = true;
        }
        return added;
    }

    @Override
    public boolean addEdge(V a, V b, L l) {
        boolean added = false;
        if(nodes.containsKey(a) && nodes.containsKey(b) && !this.containsEdge(a,b)){
            nodes.get(a).add(new Edge(a,b,l));
            if(!this.isDirected()) this.addEdge(b,a,l);
            added = true;
        }
        return added;
    }

    @Override
    public boolean containsNode(V a) {
        return this.nodes.containsKey(a);
    }

    @Override
    public boolean containsEdge(V a, V b) {
        boolean found = false;
        if(nodes.containsKey(a) && nodes.containsKey(b)){
            for(Edge e : nodes.get(a)){
                if(e.getStart() == a && e.getEnd() == b) found =  true;
            }
        }
        return found;
    }

    @Override
    public boolean removeNode(V a) {
        boolean removed = false;
        if(this.nodes.containsKey(a)){
            for(V node : this.nodes.keySet()){
                Iterator<Edge<V,L>> iterator = this.nodes.get(node).iterator();
                while(iterator.hasNext()) {
                    Edge e = iterator.next();
                    if(e.getEnd() == a) iterator.remove();
                }
            }
            this.nodes.remove(a);
            removed = true;
        }

        return removed;
    }

    @Override
    public boolean removeEdge(V a, V b) {
        boolean removed = false;
        Iterator<Edge<V,L>> iterator;
        Edge tmpEdge;
        if (this.containsNode(a) && this.containsNode(b)){
            iterator = this.nodes.get(a).iterator();
            while(iterator.hasNext()) {
                 tmpEdge = iterator.next();
                if(tmpEdge.getEnd() == b) {
                    iterator.remove();
                    removed = true;
                }
            }
            if (!this.directed){
                iterator = this.nodes.get(b).iterator();
                while(iterator.hasNext()) {
                    tmpEdge = iterator.next();
                    if(tmpEdge.getEnd() == a) iterator.remove();
                }
            }

        }
        return removed;
    }

    @Override
    public int numNodes() {
        return this.nodes.size();
    }

    @Override
    public int numEdges() {
        int tot = 0;
        for(V node : this.nodes.keySet()) tot += this.nodes.get(node).size();
        return tot;
    }

    @Override
    public ArrayList<V> getNodes() {
        ArrayList<V> nodes = new ArrayList<>(this.nodes.size());
        nodes.addAll(this.nodes.keySet());
        return nodes;
    }

    @Override
    public ArrayList<Edge<V,L>> getEdges(){
        ArrayList<Edge<V,L>> edges = new ArrayList<>(this.numEdges());
        for(V node : this.nodes.keySet()){
            edges.addAll(this.nodes.get(node));
        }
        return edges;
    }

    public ArrayList<Edge<V,L>> getEdges(V a){
        ArrayList<Edge<V, L>> edges = new ArrayList<>(this.nodes.get(a));
        return edges;
    }

    @Override
    public ArrayList<V> getNeighbours(V a) {
        ArrayList<V> neighbors = new ArrayList<>();
        if(this.containsNode(a)){
            for (Edge<V, L> edge : this.nodes.get(a)) {
                neighbors.add(edge.getEnd());
            }
        }
        return neighbors;
    }

    @Override
    public L getLabel(V a, V b) {
        L label = null;
        if(this.containsEdge(a,b)){
            for (Edge<V, L> edge : this.nodes.get(a)) {
                if (edge.getEnd() == b) label = edge.getLabel();
            }
        }
        return label;
    }

    @Override
    public String toString() {
        String ret = "Graph.Graph: \n";
        for(V node : this.nodes.keySet()){
            ret += node + ": {\n";
            for(Edge e: this.nodes.get(node)){
                ret += "\t" + e.getStart() + " ---- " + e.getLabel() + " ----> " + e.getEnd() + "\n";
            }
            ret += "}\n";
        }
        ret += "Tot. edges = "+ this.numEdges();
        ret += "\nTot. nodes = "+ this.numNodes();
        return ret + "\n\n";
    }
}
