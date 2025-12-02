typedef struct {
	char *data;
	int length;
} string;

struct Node {
	struct string* value;
	struct Node* next;
	struct Node* prev;
};

typedef struct {
	int length;
	struct Node* head;
} List;

