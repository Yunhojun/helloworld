using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreateBoard : MonoBehaviour
{
    public GameObject board;
    public GameObject[,] boards = new GameObject[8,8];
    GameObject Manager;
    // Start is called before the first frame update
    void Start()
    {
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
