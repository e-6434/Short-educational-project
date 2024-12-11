#Erfan-ebrahimkhani
#پروژه جست وجوی ناآگاهانه به روش عمقی در درس هوش مصنوعی 
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=" ")

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# مثال استفاده از الگوریتم جستجوی عمقی
my_graph = {
    'A': ['B', 'C'],        #    0                         (A)
    'B': ['D', 'E'],        #    1              (B)                     (C)
    'C': ['F'],             #    2        (D)         (E)           (*)     (F)                          
    'D': ['W','Z'],         #    3      (W) (Z)     (*) (*)               (*) (*)                         
    'E': [],                #    4                                               
    'F': [],                #    5                                                           
    'W': [],                #    6                                                   
    'Z': []                 #    7                                               
    
}

start_node = 'A'
print("your search is :")
print("(جست وجوی شما به شرح زیر است):")
dfs(my_graph, start_node)