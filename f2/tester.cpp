import math
# Creating tree nodes

class NodeTree(object):

    def _init_(self, left=None, right=None):
        self.left = left
        self.right = right

    def children(self):
        return (self.left, self.right)

    def nodes(self):
        return (self.left, self.right)

    def _str_(self):
        return '%s_%s' % (self.left, self.right)


# Main function implementing huffman coding
def huffman_code_tree(node, left=True, binString=''):
    if type(node) is str:
        return {node: binString}
    (l, r) = node.children()
    d = dict()
    d.update(huffman_code_tree(l, True, binString + '0'))
    d.update(huffman_code_tree(r, False, binString + '1'))
    return d


freq = [('A', 0.44), ('B', 0.33), ('C', 0.13), ('D', 0.10),]
#freq = [('A', 0.01), ('B', 0.02), ('C', 0.03), ('D', 0.06), ('E', 0.12), ('F', 0.30), ('G', 0.46)]

freq = sorted(freq, key=lambda x: x[1], reverse=True)
nodes = freq

while len(nodes) > 1:
    (key1, c1) = nodes[-1]
    (key2, c2) = nodes[-2]
    nodes = nodes[:-2]
    node = NodeTree(key1, key2)
    nodes.append((node, c1 + c2))

    nodes = sorted(nodes, key=lambda x: x[1], reverse=True)

huffmanCode = huffman_code_tree(nodes[0][0])

print(' Char | Huffman code ')
print('----------------------')
for (char, frequency) in freq:
    print(' %-4r |%12s' % (char, huffmanCode[char]))
    
hs = 0
l_bar = 0
for (char, frequency) in freq:
    hs = hs - frequency*(math.log(frequency,2)) 
    l_bar = l_bar + (frequency * len(huffmanCode[char]))

print('Efficiency is ' + str(hs/l_bar*100) + '%')






gen_mat = [1 0 0 0 1 0 1; 0 1 0 0 1 1 1; 0 0 1 0 0 1 0; 0 0 0 1 0 1 0];
disp("Minimum distance of linear block code with Generator Matrix-")
disp(gen_mat);
wt = min_dist(gen_mat);
disp(wt);


% min_dist Calculate the minimum distance of a linear block code for a given generator matrix gen_mat.
function wt = min_dist(g)
% Convert g into parity check matrix h
h = gen2par(g);
n = size(h, 2);

for wt = 2:n
    for i = 1:(n-wt+1)
        isSum0 = test(h(:,i), i, 1);
        if isSum0
            break;
        end
    end
    if isSum0
        break;
    end
end

function isSum0 = test(psum, i, numCols)
% Returns true if the GF sum of column i and any remaining wt-1 columns is 0.
% This is a recursive function that add wt columns in matrix h.
% psum    -- GF sum of the previous numCols columns
% i       -- index of the previous column
% numCols -- recursion depth (number of columns already added)

if numCols >= wt
    isSum0 = (sum(psum)==0);
else
    numCols = numCols + 1;
    for j = (i+1):(n-wt+numCols)
        isSum0 = test(gfadd(psum, h(:,j)), j, numCols);
        if isSum0
            break;
        end
    end
end

end     % test
end