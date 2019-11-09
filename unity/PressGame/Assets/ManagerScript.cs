using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ManagerScript : MonoBehaviour
{
    [SerializeField]
    GameObject obj;
    public int score = 0;
    public bool lever;
    float cycle = 2f;
    float time;
    // Start is called before the first frame update
    void Start()
    {
        time = 0;
        lever = false;
    }

    // Update is called once per frame
    void Update()
    {
        print(score);
        time += Time.deltaTime;
        if(time >= cycle)
        {
            ins();
        }
    }

    private void OnMouseDown()
    {
        if (!lever)
        {
            lever = true;
            GetComponent<MeshRenderer>().material.color = Color.red;
        }
    }

    void ins()
    {
        Instantiate<GameObject>(obj, new Vector3(-10f, -1.5f, 0f), Quaternion.identity);      
        time = 0;
    }
}
