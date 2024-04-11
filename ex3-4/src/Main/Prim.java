package Main;

import Graph.*;
import PriorityQueue.PriorityQueue;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Prim {
    /**
     * Perform Main.Prim algorithm on the given graph
     *
     * @param graph Graph.Graph object
     * @return a collection containing the edges that form the MSF on the given graph
     * @param <V> type of the graph nodes
     * @param <L> type of the graph edge weight
     */
    public static <V, L extends Number & Comparable> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        Set<V> visited = new HashSet<>();
        List<AbstractEdge<V, L>> resultEdges = new ArrayList<>();

        PriorityQueue<AbstractEdge<V, L>> priorityQueue = new PriorityQueue<AbstractEdge<V, L>>(new MyComparator<>());

        for (V node : graph.getNodes()) {
            if (!visited.contains(node)) {
                visited.add(node);

                for (Edge<V, L> edge : graph.getEdges(node)) {
                    priorityQueue.push(edge);
                }

                while (!priorityQueue.empty()) {
                    AbstractEdge<V, L> minEdge = priorityQueue.top();
                    priorityQueue.pop();

                    V start = minEdge.getStart();
                    V end = minEdge.getEnd();

                    if (!visited.contains(end)) {
                        visited.add(end);
                        resultEdges.add(minEdge);

                        for (Edge<V, L> adjacentEdge : graph.getEdges(end)) {
                            priorityQueue.push(adjacentEdge);
                        }
                    }
                }
            }
        }

        return resultEdges;
    }

    public static void main(String[] args) {
        Graph<String, Double> graph = new Graph<String, Double>(false, true);

        String sep = ",";
        String line;
        try {
            BufferedReader buffer = new BufferedReader(new FileReader("/Users/lucab/Desktop/repo/laboratorio-algoritmi-2022-2023/ex3-4/src/data/italian_dist_graph.csv"));
            while ((line = buffer.readLine()) != null) {
                String[] fields = line.split(sep);
                graph.addNode(fields[0]);
                graph.addNode(fields[1]);
                graph.addEdge(fields[0], fields[1], Double.valueOf(fields[2]));
                System.out.println(fields[0] + "---- " + fields[2] + " ----> " +fields[1]);
            }
        } catch (IOException e) {
            System.out.println("Some error occured while loading datat into graph. See error: ");
            e.printStackTrace();
        }
        System.out.println("Caricamento grafo completato\nNodi: \t"+graph.numNodes() + "\nArchi: \t" + graph.numEdges());

        System.out.println("Esecuzione dell'algoritmo di Main.Prim");
        long startTime = System.currentTimeMillis();
        Collection<? extends AbstractEdge<String, Double>> mst = Prim.minimumSpanningForest(graph);
        double duration = (double) (System.currentTimeMillis() - startTime) ;

        double totalDistance = 0;
        for(AbstractEdge e : mst) totalDistance+= (double) e.getLabel();
        totalDistance = totalDistance/1000;

        System.out.println("Algoritmo di Main.Prim eseguito (" + duration + " ms): " + mst.size() + " archi");
        System.out.println("Distanza totale: " + totalDistance + " Km");
    }
}
