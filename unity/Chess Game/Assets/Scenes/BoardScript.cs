using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardScript : MonoBehaviour
{
    public bool isOnEnemy = false;
    public bool isOnFriendly = false;
    int ObjNum = 0;
    GameObject Manager = null;
    public GameObject Unit = null;
    public int x;
    public int y;
    // Start is called before the first frame update
    void Start()
    {
        Manager = GameObject.FindGameObjectWithTag("GameController");
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerStay(Collider other)
    {
        if(other.tag == "Friendly")
        {
            isOnFriendly = true;
            Unit = other.gameObject;
            Manager.GetComponent<CreateBoard>().friendly[ObjNum] = new Vector2(x,y);
        }
        if(other.tag == "Enemy")
        {
            isOnEnemy = true;
            Unit = other.gameObject;
            Manager.GetComponent<CreateBoard>().enemy[ObjNum] = new Vector2(x, y);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.tag == "Friendly")
        {
            Unit = null;
            Manager.GetComponent<CreateBoard>().friendly[ObjNum] = new Vector2(100,100);
            isOnFriendly = false;
        }
        if (other.tag == "Enemy")
        {
            Unit = null;
            Manager.GetComponent<CreateBoard>().enemy[ObjNum] = new Vector2(100,100);
            isOnEnemy = false;
        }
    }
}
