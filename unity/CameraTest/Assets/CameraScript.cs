using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraScript : MonoBehaviour
{
    [SerializeField]
    float speed = 5f;
    [SerializeField]
    float rspeed = 100f;
    [SerializeField]
    float jumpPower = 5f;

    GameObject cam;
    GameObject subC;

    float rx;
    float ry;
    float h;
    float v;

    Rigidbody rigid;

    // Start is called before the first frame update
    void Start()
    {
        rigid = GetComponent<Rigidbody>();
        cam = GameObject.FindGameObjectWithTag("MainCamera");
        subC = GameObject.FindGameObjectWithTag("SubCamera");
        Cursor.lockState = CursorLockMode.Locked;
        rx = 0;
        ry = 0;
    }

    private void FixedUpdate()
    {
        if (cam.GetComponent<Camera>().enabled == true)
        {
            move(h, v);
            rotate();
        }
    }

    // Update is called once per frame
    void Update()
    {
        h = Input.GetAxisRaw("Horizontal");
        v = Input.GetAxisRaw("Vertical");

        rx += Input.GetAxis("Mouse X") * rspeed * Time.deltaTime ;
        ry += Input.GetAxis("Mouse Y") * rspeed * Time.deltaTime ;
        
    }

    private void move(float h, float v)
    {
        Vector3 dir = new Vector3(h, 0, v);      
        transform.Translate(dir.normalized * speed * Time.deltaTime);
        cam.transform.position = transform.position + Vector3.up * 1;
        subC.transform.position = transform.position + Vector3.up * 15;
    }

    private void rotate()
    {    
        cam.transform.rotation = Quaternion.Euler(-ry, rx, 0);
        transform.rotation = Quaternion.Euler(0, rx, 0);
    }

    private void OnCollisionStay(Collision collision)
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            rigid.AddForce(Vector3.up * jumpPower, ForceMode.Impulse);
        }
    }
}
