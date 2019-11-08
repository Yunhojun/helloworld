using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class objScript : MonoBehaviour
{
    public Vector3 direction;
    private Vector3 realdir;
    public bool goodObj;
    [SerializeField]
    public float speed = 1;
    GameObject Changer;
    GameObject Clear;
    GameObject Remover;
    GameObject Manager;
    Vector3 newdir;
    
    // Start is called before the first frame update
    void Start()
    {
        print(goodObj);
        direction = new Vector3(1, 0, 0);
        Changer = GameObject.FindGameObjectWithTag("Changer");
        Remover = GameObject.FindGameObjectWithTag("Remover");
        Clear = GameObject.FindGameObjectWithTag("Clear");
        Manager = GameObject.FindGameObjectWithTag("GameController");

        if (goodObj == true)
        {
            GetComponent<MeshRenderer>().material.color = Color.green;
        }
        else
        {
            GetComponent<MeshRenderer>().material.color = Color.red;
        }
    }

    // Update is called once per frame
    void Update()
    {
        move();
    }

    void move()
    {
        realdir = direction * speed * Time.deltaTime;
        transform.Translate(realdir);
    }

    void setNewdir()
    {
        if(Manager.GetComponent<CreaterScript>().dirChange == true)
        {
            newdir = new Vector3(0, 0, -1);
        }
        else
        {
            newdir = new Vector3(1, 0, 0);
        }
    }

    private void OnCollisionStay(Collision collision)
    {
        if (collision.gameObject == Changer)
        {
            float rotationSpeed = 4f;
            direction = Vector3.Lerp(direction, newdir, rotationSpeed * Time.deltaTime);
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject == Clear)
        {
            Destroy(this.gameObject);
            if(goodObj == true)
            {
                Manager.GetComponent<CreaterScript>().score += 10;
            }
            else if(goodObj == false)
            {
                Manager.GetComponent<CreaterScript>().score -= 10;
            }
        }
        else if(collision.gameObject == Remover)
        {
            Destroy(this.gameObject);
        }
        else if(collision.gameObject == Changer)
        {
            setNewdir();
        }
    }
}
