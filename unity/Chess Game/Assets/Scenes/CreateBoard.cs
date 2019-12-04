using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreateBoard : MonoBehaviour
{
    public GameObject board;
    GameObject[,] boards = new GameObject[8,8];
    Vector2[] enemy = new Vector2[10];
    Vector2[] friendly = new Vector2[10];
    // Start is called before the first frame update
    void Start()
    {
        for(int i=0; i<10; i++)
        {
            enemy[i] = new Vector2(100, 100);
            friendly[i] = new Vector2(100, 100);
        }
        createBoard();        
    }

    // Update is called once per frame
    void Update()
    {

    }

    void createBoard()
    {
        bool black = false;
        for (int x= 0; x<8; x++)
        {
            for(int y = 0; y<8; y++)
            {
                boards[x,y] = Instantiate<GameObject>(board, new Vector3(x, 0, y), Quaternion.identity);
                boards[x,y].transform.parent = transform;
                boards[x,y].GetComponent<BoardScript>().setpos(x, y);
                if (black)
                {
                    boards[x, y].GetComponent<MeshRenderer>().material.color = Color.black;
                }
                else
                {
                    boards[x, y].GetComponent<MeshRenderer>().material.color = Color.white;
                }
                black = !black;
            }
            black = !black;
        }
    }

    public Vector2[] getEnemy()
    {
        return enemy;
    }

    public void setEnemy(int i, Vector2 pos)
    {
        enemy[i] = pos;
    }

    public Vector2[] getFriendly()
    {
        return friendly;
    }

    public void setFriendly(int i, Vector2 pos)
    {
        friendly[i] = pos;
    }

    public GameObject getBoards(float x, float y)
    {
        int xint = Mathf.RoundToInt(x);
        int yint = Mathf.RoundToInt(y);
        return boards[xint, yint];
    }

    public GameObject getBoards(int x, int y)
    {
        return boards[x, y];
    }
}
