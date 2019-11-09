using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PressScript : MonoBehaviour
{
    GameObject lever;
    Rigidbody rigid;
    [SerializeField]
    float speed = 10f;
    [SerializeField]
    float forcef = 100f;
    bool up;
    [SerializeField]
    GameObject obj2;
    GameObject manager;

    // Start is called before the first frame update
    void Start()
    {
        manager = GameObject.FindGameObjectWithTag("GameController");
        up = false;
        rigid = gameObject.GetComponent<Rigidbody>();
        lever = GameObject.FindGameObjectWithTag("GameController");
    }

    // Update is called once per frame
    void Update()
    {
        if(lever.GetComponent<ManagerScript>().lever && !up)
        {
            downPress();
        }
        if (up)
        {
            upPress();
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "belt")
        {
            up = true;
        }
       
        
    }
    

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "obj")
        {
            Destroy(other.gameObject,0f);
            Instantiate<GameObject>(obj2, other.transform.position + Vector3.down * 0.5f, Quaternion.identity);
            obj2.GetComponent<objScript>().Pressed = true;
            manager.GetComponent<ManagerScript>().score += 10;
        }
    }

    void upPress()
    {
        if (transform.position.y < 4.5f)
        {
            transform.Translate(Vector3.up * speed * Time.deltaTime);
        }
        else
        {
            lever.GetComponent<ManagerScript>().lever = false;
            lever.GetComponent<MeshRenderer>().material.color = Color.green;
            up = false;
            return;
        }
    }

    void downPress()
    {
        rigid.AddForce(Vector3.down * forcef * Time.deltaTime,ForceMode.Impulse);
    }
}
