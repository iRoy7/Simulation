#include <stdio.h>
#include "Common.h"

int main()
{
	freopen("Linked_List_Tree.txt", "r", stdin);
	setbuf(stdout, NULL);

	printf("Linked-List Tree Op.\n");
	int simulCnt; scanf("%d", &simulCnt);

	for (int sc = 1; sc <= simulCnt; sc++)
	{
		int cmd; scanf("%d", &cmd);
		printf("CMD> (%d)\n", cmd);

		switch (cmd)
		{
		case 1: // Add
		{
			int id, pid, val;
			scanf("%d %d %d", &id, &pid, &val);
			AddNode(id, pid, val);
			printf("Current # of nodes = (%d)\n", GetCurNodeCnt());
			break;
		}
		case 2: // Remove
		{
			int id; scanf("%d", &id);
			printf("Remove node's sum value = (%d)\n", RemoveNode(id));
			break;
		}
		case 3: // Move
		{
			int id, pid;
			scanf("%d %d", &id, &pid);
			printf("Sum value of cur parent including itself = (%d)\n", GetValueSum(pid));
			MoveNode(id, pid);
			printf("Sum value of now parent including itself = (%d)\n", GetValueSum(pid));
			break;
		}
		case 4: // Sum Value
		{
			int id; scanf("%d", &id);
			printf("Sum value of all child including itself = (%d)\n",GetValueSum(id));
		}
		default:
			printf("Wrong command, move to next command\n");
			break;
		}
	}

	return 0;
}