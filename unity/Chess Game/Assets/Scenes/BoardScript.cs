using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardScript : MonoBehaviour
{
    [SerializeField]
    bool isOnEnemy = false;
    [SerializeField]
    bool isOnFriendly = false;
    int ObjNum = 0;
    GameObject Manager = null;
    GameObject Unit = null;
    int x;
    int y;
    Vector2 pos;
    // Start is called before the first frame update
    private void Awake()
    {
        Manager = GameObject.FindGameObjectWithTag("GameController");
    }

    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void setpos(int xVal, int yVal)
    {
        x = xVal;
        y = yVal;
        pos = new Vector2(x, y);
    }

    public Vector2 getpos()
    {
        return pos;
    }

    private void OnTriggerStay(Collider other)
    {
        if(other.tag == "Friendly")
        {
            isOnFriendly = true;
            Unit = other.gameObject;
            Manager.GetComponent<CreateBoard>().setFriendly(ObjNum, new Vector2(x, y));
        }
        if(other.tag == "Enemy")
        {
            isOnEnemy = true;
            Unit = other.gameObject;            
            Manager.GetComponent<CreateBoard>().setEnemy(ObjNum, new Vector2(x, y));
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.tag == "Friendly")
        {
            Unit = null;
            Manager.GetComponent<CreateBoard>().setFriendly(ObjNum, new Vector2(100, 100));
            isOnFriendly = false;
        }
        if (other.tag == "Enemy")
        {
            Unit = null;
            Manager.GetComponent<CreateBoard>().setEnemy(ObjNum, new Vector2(100, 100));
            isOnEnemy = false;
        }
    }

    public bool getisOnEnemy()
    {
        return isOnEnemy;
    }

    public bool getisOnFriendly()
    {
        return isOnFriendly;
    }
    public GameObject getUnit()
    {
        return Unit;
    }
}
