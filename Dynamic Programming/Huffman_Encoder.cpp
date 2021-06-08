
class node {
	char data;
	int cost;
	node* left;
	node* right;

public:
	node(char data, int cost) {
		this->data = data;
		this->cost = cost;
		left = NULL;
		right = NULL;
	}

	int compare(node* other) {
		return this->cost > other->cost;
	}
};

class Huffman_Encoder {

	unordered_map <char, string> encoder;
	unordered_map < string, char > decoder;
public:

	Huffman_Encoder(string feeder) {
		// create a freq map of feeder string
		unordered_map < char, int> freq_map;
		for(int i=0;i<feeder.length();i++) {
			char cc = feeder[i];
			if(f.find(cc) != f.end()) {
				int ov = freq_map[cc];
				ov = ov +1;
				freq_map[cc] = ov;
			}
			else {
				freq_map[cc].push_back(1);
			}
		}

		// create a min heap of trees
		priority_queue < node, vector <node > , greater <node> > minHeap;
		for(auto node : freq_map )  {
			minHeap.push(node);
		}

		// combine all nodes until one node is left in the heap
		while(minHeap.size() >= 1)  {
			node* minone = minHeap.front();
			minHeap.pop();
			node* mintwo = minHeap.front();
			minHeap.pop();

			node* combined = minone.cost + min
		}
	}
};












