using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreateBoard : MonoBehaviour
{
    public GameObject board;
    public GameObject[,] boards = new GameObject[8,8];
    GameObject Manager;
    public Vector2[] enemy = new Vector2[10];
    public Vector2[] friendly = new Vector2[10];
    // Start is called before the first frame update
    void Start()
    {
        for(int i=0; i<10; i++)
        {
            enemy[i] = new Vector2(100, 100);
            friendly[i] = new Vector2(100, 100);
        }
        Manager = GameObject.FindGameObjectWithTag("GameController");
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
                boards[x,y].transform.parent = Manager.transform;
                boards[x, y].GetComponent<BoardScript>().x = x;
                boards[x, y].GetComponent<BoardScript>().y = y;
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
}
