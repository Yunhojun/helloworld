using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CubeBehaviour : MonoBehaviour
{
    Ray ray;
    RaycastHit hit;
    Vector3 postomove;
    [SerializeField]
    float moveSpeed = 5f;
    Vector3 temp;
    [SerializeField]
    GameObject Q = null;
    [SerializeField]
    float Qspeed = 5f;
    Vector3 pos;
    public int damage;

    // Start is called before the first frame update
    void Start()
    {
        damage = 10;
    }

    private void FixedUpdate()
    {
        move();        
        if (Input.GetKeyDown(KeyCode.Q))
        {
            skillQ();
        }
    }

    // Update is called once per frame
    void Update()
    {
        ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        if (Physics.Raycast(ray, out hit, 100f))
        {
            pos = hit.point;
            if (Input.GetMouseButton(1))
            {
                postomove = hit.point;
                temp = transform.position;
                turn(postomove);
            }        
        }        
    }

    void move()
    {
        float dis = Vector3.Distance(transform.position, postomove);
        Vector3 dir = postomove - transform.position;
        Vector3 test = postomove - temp;
        dir.y = 0;
        if ((dir.x * test.x > 0 && dir.z * test.z > 0) && dis > 0.51f)
        {
            transform.Translate(dir.normalized * Time.deltaTime * moveSpeed, Space.World);            
        }
    }

    void turn(Vector3 pos)
    {
        Vector3 dir = pos - transform.position;
        dir.y = 0;
        transform.rotation = Quaternion.LookRotation(dir);
    }

    void skillQ()
    {
        Vector3 dir = pos - transform.position;
        dir.y = 0;
        GameObject newQ = Instantiate<GameObject>(Q, transform.position, Quaternion.identity);
        newQ.GetComponent<Rigidbody>().AddForce(dir.normalized * Qspeed * Time.deltaTime, ForceMode.VelocityChange);
        turn(pos);
    }
}