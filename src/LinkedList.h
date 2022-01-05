/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
    void *data;
    struct Node *next;
} Node;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    assert(node);
    newNode->data = data;
    newNode->next = NULL;
     return newNode;
}

Node *emptyNode()
{
    return (Node *)malloc(sizeof(Node));
}

void show(Node *node)
{
    Node *current = node;
    if(!node) return;
    while (current != NULL){
        current = current->next;
        printf("%s\n", (char *)current->data);
    }
}

void append(int data, Node *top)
{
    Node *current = NULL;
    if(!top) {
        top = newNode(data);
        return;
    }
    current = node;
    while (current->next != NULL){
      current = current->next;
    }
    current->next = createnode(data);
}


void delete(int data, Node *top)
{
    Node *previous = top;
    Node *current = top->next;
    while(current != NULL){
        if(current->data == data){
            previous->next = current->next;
            if(current == top)
                top = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void destroy(Node *top)
{
    Node *next;
    Node *current = top;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(top);
}
